// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ZZPlayerController.generated.h"

class UZZAgentManagerComponent;

UCLASS()
class ZUZANNAKRAWIEC_API AZZPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AZZPlayerController();
	void OpenStartupMenu();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Agent|AgentManager")
	UZZAgentManagerComponent* GetAgentManagerComponent() const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	UZZAgentManagerComponent* AgentManagerComponent = nullptr;
};
