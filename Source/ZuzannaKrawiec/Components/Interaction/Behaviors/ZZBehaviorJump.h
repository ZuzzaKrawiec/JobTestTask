// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Interaction/ZZInteractionBehavior.h"
#include "ZZBehaviorJump.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class ZUZANNAKRAWIEC_API UZZBehaviorJump : public UZZInteractionBehavior
{
	GENERATED_BODY()
public:
	virtual void BehaviorStartExecute(AActor* InCallingActor) override;
	virtual void BehaviorStopExecute(AActor* InCallingActor) override;
	virtual void BehaviorAction_Implementation(AActor* InCallingActor) override;
	void BehaviorActionTimer();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpPower = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LoopDuration = 0.5f;

	FTimerHandle JumpTimer;

	UPROPERTY()
	ACharacter* CachedCharacter = nullptr;
};
