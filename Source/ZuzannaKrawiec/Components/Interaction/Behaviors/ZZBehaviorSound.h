// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Interaction/ZZInteractionBehavior.h"
#include "ZZBehaviorSound.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class ZUZANNAKRAWIEC_API UZZBehaviorSound : public UZZInteractionBehavior
{
	GENERATED_BODY()
public:
	virtual void BehaviorStartExecute(AActor* InCallingActor) override;
	virtual void BehaviorStopExecute(AActor* InCallingActor) override;
	void BehaviorActionTimer();
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LoopDuration = 0.5f;

	FTimerHandle SoundTimer;
};
