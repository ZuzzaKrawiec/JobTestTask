// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ZZPlayerController.h"
#include "Components/AgentControl/ZZAgentManagerComponent.h"
#include "GameMode/ZZHUD.h"

AZZPlayerController::AZZPlayerController()
{
	AgentManagerComponent = CreateDefaultSubobject<UZZAgentManagerComponent>(FName("Agent Manager Component"));
	AgentManagerComponent->bEditableWhenInherited = true;
}
void AZZPlayerController::BeginPlay()
{
	Super::BeginPlay();
	OpenStartupMenu();

}
void AZZPlayerController::OpenStartupMenu()
{
	AZZHUD* HUD = Cast<AZZHUD>(GetHUD());
	if (!HUD)
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZPlayerController::OpenStartupMenu HUD is null"));
		return;
	}
	HUD->OpenMenu(EMenuType::MainMenu);
}

UZZAgentManagerComponent* AZZPlayerController::GetAgentManagerComponent() const
{
	return AgentManagerComponent;
}