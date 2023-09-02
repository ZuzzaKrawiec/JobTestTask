// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Interaction/ZZInteractionBehavior.h"
#include "ZZBehaviorChangeColor.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class ZUZANNAKRAWIEC_API UZZBehaviorChangeColor : public UZZInteractionBehavior
{
	GENERATED_BODY()
public:
	virtual void BehaviorStartExecute(AActor* InCallingActor) override;
	virtual void BehaviorStopExecute(AActor* InCallingActor) override;
	virtual void BehaviorAction_Implementation(AActor* InCallingActor) override;
protected:
	UPROPERTY(EditAnywhere)
	TArray<UMaterialInterface*> Materials;
};
