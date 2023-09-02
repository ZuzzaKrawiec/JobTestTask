// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ZZInteractionBehavior.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZUZANNAKRAWIEC_API UZZInteractionBehavior : public UActorComponent
{
	GENERATED_BODY()

public:	
	UZZInteractionBehavior();
	virtual void BehaviorStartExecute(AActor* InCallingActor);
	virtual void BehaviorStopExecute(AActor* InCallingActor);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BehaviorAction(AActor* InCallingActor);
	virtual void BehaviorAction_Implementation(AActor* InCallingActor);

protected:
	virtual void BeginPlay() override;
	UPROPERTY()
	AActor* CallingActor = nullptr;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};