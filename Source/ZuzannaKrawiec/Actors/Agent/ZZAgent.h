// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Navigation/PathFollowingComponent.h"
#include "ZZAgent.generated.h"

class UZZInteractionComponent;
DECLARE_DELEGATE_TwoParams(FOnTargetReached, AZZAgent* InAgent, bool bInWasSuccessful)
UCLASS()
class ZUZANNAKRAWIEC_API AZZAgent : public ACharacter
{
	GENERATED_BODY()

public:
	AZZAgent();

	void RegisterAgentToManager();
	void UnregisterAgentToManager();

	void SetTargetGoToInteraction(UZZInteractionComponent* InInteractionComponent, FOnTargetReached InOnTargetReached);
	void AbortExecution();
	UFUNCTION()
	void OnTargetReached(FAIRequestID RequestID, EPathFollowingResult::Type Result);
	void UnbindTargetReached();
	void SetCurrentInteractionExecution(UZZInteractionComponent* InInteractionComponent);
	UZZInteractionComponent* GetCurrentInteractionExecution() const;

	void SetReached(bool bState);
	bool GetReached() const;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type Reason) override;

	FOnTargetReached OnTargetReachedCallback;

	bool bReached = false;
	bool bBound = false;
	UPROPERTY()
	UZZInteractionComponent* CurrentInteractionExecution = nullptr;
};
