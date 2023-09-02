// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AgentControl/ZZAgentManagerComponent.h"
#include "Components/Interaction/ZZInteractionComponent.h"
#include "Components/Highlight/ZZHightlightInterface.h"
#include "Actors/Agent/ZZAgent.h"

UZZAgentManagerComponent::UZZAgentManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UZZAgentManagerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UZZAgentManagerComponent::RegisterControlledAgent(AZZAgent* InControlledAgent)
{
	ControlledAgent = InControlledAgent;
}
void UZZAgentManagerComponent::UnregisterControlledAgent(AZZAgent* InControlledAgent)
{
	ControlledAgent = InControlledAgent;
}

void UZZAgentManagerComponent::AgentInteractionTarget(UZZInteractionComponent* InInteractionComponent)
{
	if (!ControlledAgent)
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZAgentManagerComponent::AgentInteractionTarget no agent"));
		return;
	}
	FOnTargetReached OnCompleted;
	OnCompleted.BindLambda([=](AZZAgent* InAgent, bool bInWasSuccessful) {
		if (bInWasSuccessful)
		{
			InInteractionComponent->StartInteraction(InAgent);
			InAgent->SetReached(true);
		}
	});
	ControlledAgent->SetTargetGoToInteraction(InInteractionComponent, OnCompleted);
}
void UZZAgentManagerComponent::AbortExecution()
{
	if (!ControlledAgent)
	{
		UE_LOG(LogTemp, Warning, TEXT("UZZAgentManagerComponent::AbortExecution no agent"));
		return;
	}
	ControlledAgent->AbortExecution();	

	
	UZZInteractionComponent* InteractionComponent = ControlledAgent->GetCurrentInteractionExecution();
	if (InteractionComponent)
	{
		bool bImplements = InteractionComponent->GetOwner()->Implements<UZZHightlightInterface>();
		if (bImplements)
		{
			IZZHightlightInterface::Execute_SetHighlight(InteractionComponent->GetOwner(), EHighlightFlag::Action, false);
		}
		if (ControlledAgent->GetReached())
		{
			InteractionComponent->StopInteraction(ControlledAgent);
		}
		ControlledAgent->SetCurrentInteractionExecution(nullptr);
	}
}