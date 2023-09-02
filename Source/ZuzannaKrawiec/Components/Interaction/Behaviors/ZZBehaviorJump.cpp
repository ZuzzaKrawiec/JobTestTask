// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Interaction/Behaviors/ZZBehaviorJump.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UZZBehaviorJump::BehaviorStartExecute(AActor* InCallingActor)
{
	Super::BehaviorStartExecute(InCallingActor);
	CachedCharacter = Cast<ACharacter>(CallingActor);
	if (CachedCharacter)
	{
		GetWorld()->GetTimerManager().SetTimer(JumpTimer, this, &UZZBehaviorJump::BehaviorActionTimer, LoopDuration, true);
		BehaviorActionTimer();
	}
}
void UZZBehaviorJump::BehaviorStopExecute(AActor* InCallingActor)
{
	GetWorld()->GetTimerManager().ClearTimer(JumpTimer);
	Super::BehaviorStopExecute(InCallingActor);
}
void UZZBehaviorJump::BehaviorAction_Implementation(AActor* InCallingActor)
{
	CachedCharacter->GetCharacterMovement()->Launch(FVector(0.0f, 0.0f, JumpPower));
}
void UZZBehaviorJump::BehaviorActionTimer()
{
	BehaviorAction(CallingActor);
}