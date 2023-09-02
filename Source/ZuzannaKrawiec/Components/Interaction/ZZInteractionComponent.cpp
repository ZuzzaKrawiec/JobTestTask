// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Interaction/ZZInteractionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Interaction/ZZInteractionManagerComponent.h"
#include "GameMode/ZZGameState.h"
#include "Components/Interaction/ZZInteractionBehavior.h"

UZZInteractionComponent::UZZInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UZZInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	RegisterInteractionComponent();
}

void UZZInteractionComponent::EndPlay(EEndPlayReason::Type Reason) 
{
	Super::EndPlay(Reason);
	UnregisterInteractionComponent();
}
void UZZInteractionComponent::RegisterInteractionComponent()
{
	AZZGameState* GameState = Cast<AZZGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (!GameState)
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZInteractionComponent::RegisterInteractionComponent GameState is null"));
		return;
	}
	UZZInteractionManagerComponent* InteractionManagerComponent = GameState->GetInteractionManagerComponent();
	if (!InteractionManagerComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZInteractionComponent::RegisterInteractionComponent InteractionManagerComponent is null"));
		return;
	}
	InteractionManagerComponent->RegisterInteractionComponent(this);
}
void UZZInteractionComponent::UnregisterInteractionComponent()
{
	AZZGameState* GameState = Cast<AZZGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (!GameState)
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZInteractionComponent::RegisterInteractionComponent GameState is null"));
		return;
	}
	UZZInteractionManagerComponent* InteractionManagerComponent = GameState->GetInteractionManagerComponent();
	if (!InteractionManagerComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZInteractionComponent::RegisterInteractionComponent InteractionManagerComponent is null"));
		return;
	}
	InteractionManagerComponent->UnregisterInteractionComponent(this);
}
void UZZInteractionComponent::StartInteraction(AActor* InCallingActor)
{
	UseInteraction(InCallingActor, true);
}
void UZZInteractionComponent::StopInteraction(AActor* InCallingActor)
{
	UseInteraction(InCallingActor, false);
	
}
void UZZInteractionComponent::UseInteraction(AActor* InCallingActor, bool bState)
{
	TArray<UActorComponent*> OutComponents;
	GetOwner()->GetComponents(OutComponents, true);
	UZZInteractionBehavior* Behavior = nullptr;
	for (UActorComponent* Component : OutComponents)
	{
		if (!Component)
		{
			continue;
		}
		Behavior = Cast<UZZInteractionBehavior>(Component);
		if (!Behavior)
		{
			continue;
		}
		if (bState)
		{
			Behavior->BehaviorStartExecute(InCallingActor);
		}
		else
		{
			Behavior->BehaviorStopExecute(InCallingActor);
		}
	}

	
}
const FDataTableRowHandle& UZZInteractionComponent::GetInteractionDataRow() const
{
	return InteractionDataRow;
}
FInteractionData* UZZInteractionComponent::FindInteractionData()
{
	if (!InteractionDataRow.DataTable)
	{
		return nullptr;
	}
	return InteractionDataRow.DataTable->FindRow<FInteractionData>(InteractionDataRow.RowName, FString("UZZInteractionComponent::FindInteractionData"));
}