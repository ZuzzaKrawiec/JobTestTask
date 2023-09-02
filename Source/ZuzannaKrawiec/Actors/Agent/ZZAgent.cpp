// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Agent/ZZAgent.h"
#include "GameMode/ZZPlayerController.h"
#include "Components/AgentControl/ZZAgentManagerComponent.h"
#include "Components/Interaction/ZZInteractionComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "AIController.h"

AZZAgent::AZZAgent()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AZZAgent::BeginPlay()
{
	Super::BeginPlay();
	RegisterAgentToManager();
}

void AZZAgent::EndPlay(EEndPlayReason::Type Reason)
{
	Super::EndPlay(Reason);
	UnregisterAgentToManager();
}
void AZZAgent::RegisterAgentToManager()
{
	AZZPlayerController* PlayerController = Cast<AZZPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZAgent::RegisterAgentToManager PlayerController is null"));
		return;
	}

	UZZAgentManagerComponent* AgentManagerComponent = PlayerController->GetAgentManagerComponent();
	if (!AgentManagerComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZAgent::RegisterAgentToManager AgentManagerComponent is null"));
		return;
	}
	AgentManagerComponent->RegisterControlledAgent(this);
}
void AZZAgent::UnregisterAgentToManager()
{
	AZZPlayerController* PlayerController = Cast<AZZPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZAgent::UnregisterAgentToManager PlayerController is null"));
		return;
	}

	UZZAgentManagerComponent* AgentManagerComponent = PlayerController->GetAgentManagerComponent();
	if (!AgentManagerComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZAgent::UnregisterAgentToManager AgentManagerComponent is null"));
		return;
	}
	AgentManagerComponent->UnregisterControlledAgent(this);
}

void AZZAgent::SetTargetGoToInteraction(UZZInteractionComponent* InInteractionComponent, FOnTargetReached InOnTargetReached)
{
	if (!InInteractionComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZAgent::SetTargetGoToInteraction InInteractionComponent is null"));
		return;
	}
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZAgent::SetTargetGoToInteraction NO AI controller is null"));
		return;
	}
	OnTargetReachedCallback = InOnTargetReached;
	AIController->ReceiveMoveCompleted.AddDynamic(this, &AZZAgent::OnTargetReached);
	bBound = true;
	bReached = false;
	CurrentInteractionExecution = InInteractionComponent;
	AIController->MoveToActor(InInteractionComponent->GetOwner(), 130.0f, true, true, false, 0, true);
	
}

void AZZAgent::UnbindTargetReached()
{
	if (!bBound)
	{
		return;
	}
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZAgent::UnbindTargetReached NO AI controller is null"));
		return;
	}
	OnTargetReachedCallback.Unbind();
	AIController->ReceiveMoveCompleted.RemoveDynamic(this, &AZZAgent::OnTargetReached);
	bBound = false;
}
void AZZAgent::OnTargetReached(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	OnTargetReachedCallback.ExecuteIfBound(this, Result == EPathFollowingResult::Type::Success);
	UnbindTargetReached();
}
void AZZAgent::AbortExecution()
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZAgent::AbortExecution NO AI controller is null"));
		return;
	}
	GetCharacterMovement()->StopMovementImmediately();
	AIController->StopMovement();
	UnbindTargetReached();
}


void AZZAgent::SetCurrentInteractionExecution(UZZInteractionComponent* InInteractionComponent)
{
	CurrentInteractionExecution = InInteractionComponent;
}
UZZInteractionComponent* AZZAgent::GetCurrentInteractionExecution() const
{
	return CurrentInteractionExecution;
}

void AZZAgent::SetReached(bool bState)
{
	bReached = bState;
}
bool AZZAgent::GetReached() const
{
	return bReached;
}