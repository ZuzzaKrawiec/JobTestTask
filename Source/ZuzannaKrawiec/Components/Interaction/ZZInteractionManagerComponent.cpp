// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Interaction/ZZInteractionManagerComponent.h"
#include "Components/Interaction/ZZInteractionComponent.h"

UZZInteractionManagerComponent::UZZInteractionManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UZZInteractionManagerComponent::RegisterInteractionComponent(UZZInteractionComponent* InInteractionComponent)
{
	RegisteredInteractionComponents.Add(InInteractionComponent);
	OnInteractionComponentRegistered.Broadcast(InInteractionComponent);
}
void UZZInteractionManagerComponent::UnregisterInteractionComponent(UZZInteractionComponent* InInteractionComponent)
{
	RegisteredInteractionComponents.Remove(InInteractionComponent);
	OnInteractionComponentUnregistered.Broadcast(InInteractionComponent);
}
const TSet<UZZInteractionComponent*>& UZZInteractionManagerComponent::GetRegisteredInteractionComponents() const
{
	return RegisteredInteractionComponents;
}