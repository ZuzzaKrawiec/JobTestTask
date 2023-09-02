// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ZZGameState.generated.h"


class UZZInteractionManagerComponent;

UCLASS()
class ZUZANNAKRAWIEC_API AZZGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AZZGameState();

	UFUNCTION()
	UZZInteractionManagerComponent* GetInteractionManagerComponent() const;

protected:

	UPROPERTY()
	UZZInteractionManagerComponent* InteractionManagerComponent = nullptr;	
};
