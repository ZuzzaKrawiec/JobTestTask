// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ZZAgentManagerComponent.generated.h"

class AZZAgent;
class UZZInteractionComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZUZANNAKRAWIEC_API UZZAgentManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UZZAgentManagerComponent();

	void RegisterControlledAgent(AZZAgent* InControlledAgent);
	void UnregisterControlledAgent(AZZAgent* InControlledAgent);

	void AgentInteractionTarget(UZZInteractionComponent* InInteractionComponent);
	void AbortExecution();

protected:
	virtual void BeginPlay() override;

	UPROPERTY();
	AZZAgent* ControlledAgent;
};
