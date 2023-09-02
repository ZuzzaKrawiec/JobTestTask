// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Interaction/Behaviors/ZZBehaviorSound.h"

void UZZBehaviorSound::BehaviorStartExecute(AActor* InCallingActor)
{
	Super::BehaviorStartExecute(InCallingActor);
	GetWorld()->GetTimerManager().SetTimer(SoundTimer, this, &UZZBehaviorSound::BehaviorActionTimer, LoopDuration, true);
	BehaviorActionTimer();
}
void UZZBehaviorSound::BehaviorStopExecute(AActor* InCallingActor)
{
	GetWorld()->GetTimerManager().ClearTimer(SoundTimer);
	Super::BehaviorStopExecute(InCallingActor);
}

void UZZBehaviorSound::BehaviorActionTimer()
{
	BehaviorAction(CallingActor);
}