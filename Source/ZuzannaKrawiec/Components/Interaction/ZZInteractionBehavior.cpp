// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Interaction/ZZInteractionBehavior.h"

UZZInteractionBehavior::UZZInteractionBehavior()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UZZInteractionBehavior::BeginPlay()
{
	Super::BeginPlay();
}

void UZZInteractionBehavior::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


void UZZInteractionBehavior::BehaviorStartExecute(AActor* InCallingActor)
{
	CallingActor = InCallingActor;
}
void UZZInteractionBehavior::BehaviorStopExecute(AActor* InCallingActor)
{
	CallingActor = nullptr;
}
void UZZInteractionBehavior::BehaviorAction_Implementation(AActor* InCallingActor)
{

}