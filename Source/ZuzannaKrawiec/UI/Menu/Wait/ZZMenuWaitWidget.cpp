// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Menu/Wait/ZZMenuWaitWidget.h"
#include "Settings/ZZUISettings.h"
#include "GameMode/ZZPlayerController.h"
#include "Components/AgentControl/ZZAgentManagerComponent.h"
#include "Kismet/GameplayStatics.h"

void UZZMenuWaitWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonAbort->OnButtonPressed.AddDynamic(this, &UZZMenuWaitWidget::AbortAction);
}

void UZZMenuWaitWidget::AbortAction(UZZButtonWidget* InButton)
{
	TSoftClassPtr<UZZMenuWidget> MainMenuClass = *GetDefault<UZZUISettings>()->MenuWidgetClass.Find(EMenuType::MainMenu);
	if (MainMenuClass.IsNull())
	{
		return;
	}

	AZZPlayerController* PlayerController = Cast<AZZPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZMenuMainWidget::OnButtonPressed PlayerController is null"));
		return;
	}
	UZZAgentManagerComponent* AgentManagerComponent = PlayerController->GetAgentManagerComponent();
	if (!AgentManagerComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZMenuMainWidget::OnButtonPressed AgentManagerComponent is null"));
		return;
	}

	AgentManagerComponent->AbortExecution();

	OnMenuOpen.ExecuteIfBound(MainMenuClass.LoadSynchronous());
}