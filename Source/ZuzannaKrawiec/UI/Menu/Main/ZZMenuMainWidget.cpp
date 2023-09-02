// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Menu/Main/ZZMenuMainWidget.h"
#include "GameMode/ZZGameState.h"
#include "GameMode/ZZPlayerController.h"
#include "Components/AgentControl/ZZAgentManagerComponent.h"
#include "Components/Interaction/ZZInteractionManagerComponent.h"
#include "Components/Interaction/ZZInteractionComponent.h"
#include "UI/Buttons/ZZButtonSimpleWidget.h"
#include "Settings/ZZUISettings.h"
#include "Components/Highlight/ZZHightlightInterface.h"
#include "Kismet/GameplayStatics.h"


void UZZMenuMainWidget::NativeConstruct()
{
	Super::NativeConstruct();
	FindInteractionManager();
	GenerateInteraction();
}
void UZZMenuMainWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if(CachedInteractionManagerComponent)
	{
		CachedInteractionManagerComponent->OnInteractionComponentRegistered.RemoveDynamic(this, &UZZMenuMainWidget::AddInteraction);
		CachedInteractionManagerComponent->OnInteractionComponentRegistered.RemoveDynamic(this, &UZZMenuMainWidget::RemoveInteraction);
	}
}
void UZZMenuMainWidget::GenerateInteraction()
{
	if (!CachedInteractionManagerComponent)
	{
		return;
	}
	for (UZZInteractionComponent* InteractionComponent : CachedInteractionManagerComponent->GetRegisteredInteractionComponents())
	{
		if (!InteractionComponent)
		{
			continue;
		}
		AddInteraction(InteractionComponent);
	}
	CachedInteractionManagerComponent->OnInteractionComponentRegistered.AddDynamic(this, &UZZMenuMainWidget::AddInteraction);
	CachedInteractionManagerComponent->OnInteractionComponentRegistered.AddDynamic(this, &UZZMenuMainWidget::RemoveInteraction);
}
void UZZMenuMainWidget::AddInteraction(UZZInteractionComponent * InInteractionComponent)
{
	if (GetDefault<UZZUISettings>()->SimpleButtonWidgetClass.IsNull())
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZMenuMainWidget::AddInteraction SimpleButtonWidgetClass is null"));
		return;
	}

	UZZButtonSimpleWidget* ButtonSimpleWidget = Cast<UZZButtonSimpleWidget>(CreateWidget(GetOwningPlayer(), GetDefault<UZZUISettings>()->SimpleButtonWidgetClass.LoadSynchronous()));
	if (!ButtonSimpleWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZMenuMainWidget::AddInteraction widget failed"));
		return;
	}
	Interactions->AddChildToHorizontalBox(ButtonSimpleWidget);
	ButtonSimpleWidget->SetData(InInteractionComponent);
	ButtonSimpleWidget->SetPadding(FMargin(8.0f));
	InteractionsList.Add(ButtonSimpleWidget);

	ButtonSimpleWidget->OnButtonPressed.AddDynamic(this, &UZZMenuMainWidget::OnButtonPressed);
	ButtonSimpleWidget->OnButtonHovered.AddDynamic(this, &UZZMenuMainWidget::OnButtonHovered);
	ButtonSimpleWidget->OnButtonUnhovered.AddDynamic(this, &UZZMenuMainWidget::OnButtonUnhovered);

}
void UZZMenuMainWidget::RemoveInteraction(UZZInteractionComponent* InInteractionComponent)
{
	for (int32 i = 0; i < InteractionsList.Num(); i++)
	{
		if (!InteractionsList[i])
		{
			return;
		}
		InteractionsList[i]->RemoveFromParent();
		InteractionsList.RemoveAt(i);
		break;
	}
}

void UZZMenuMainWidget::FindInteractionManager()
{
	AZZGameState* GameState = Cast<AZZGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (!GameState)
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZMenuMainWidget::GenerateInteraction GameState is null"));
		return;
	}
	CachedInteractionManagerComponent = GameState->GetInteractionManagerComponent();
}

void UZZMenuMainWidget::OnButtonPressed(UZZButtonWidget* InButton)
{
	SetHighlightForButton(InButton, EHighlightFlag::Hovered, false);
	SetHighlightForButton(InButton, EHighlightFlag::Action, true);

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

	UZZButtonSimpleWidget* ButtonSimpleWidget = Cast<UZZButtonSimpleWidget>(InButton);
	if (!ButtonSimpleWidget)
	{
		return;
	}
	AgentManagerComponent->AgentInteractionTarget(ButtonSimpleWidget->GetInteractionComponent());
	OpenWaitMenu();
}

void UZZMenuMainWidget::OnButtonHovered(UZZButtonWidget* InButton)
{
	SetHighlightForButton(InButton, EHighlightFlag::Hovered, true);
}

void UZZMenuMainWidget::OnButtonUnhovered(UZZButtonWidget* InButton)
{
	SetHighlightForButton(InButton, EHighlightFlag::Hovered, false);
}

void UZZMenuMainWidget::SetHighlightForButton(UZZButtonWidget* InButton, EHighlightFlag InFlag, bool bState)
{
	UZZButtonSimpleWidget* ButtonSimpleWidget = Cast<UZZButtonSimpleWidget>(InButton);
	if (!ButtonSimpleWidget)
	{
		return;
	}
	if (!ButtonSimpleWidget->GetInteractionComponent())
	{
		return;
	}
	bool bImplements = ButtonSimpleWidget->GetInteractionComponent()->GetOwner()->Implements<UZZHightlightInterface>();
	if (!bImplements)
	{
		return;
	}
	IZZHightlightInterface::Execute_SetHighlight(ButtonSimpleWidget->GetInteractionComponent()->GetOwner(), InFlag, bState);
}


void UZZMenuMainWidget::OpenWaitMenu()
{
	TSoftClassPtr<UZZMenuWidget> WaitMenuClass = *GetDefault<UZZUISettings>()->MenuWidgetClass.Find(EMenuType::WaitMenu);
	if (WaitMenuClass.IsNull())
	{
		return;
	}
	OnMenuOpen.ExecuteIfBound(WaitMenuClass.LoadSynchronous());
}