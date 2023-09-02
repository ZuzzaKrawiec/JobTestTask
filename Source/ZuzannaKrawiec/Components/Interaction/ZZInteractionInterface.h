// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ZZInteractionInterface.generated.h"

class UZZInteractionComponent;

UINTERFACE(MinimalAPI)
class UZZInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class ZUZANNAKRAWIEC_API IZZInteractionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface|Interaction")
	UZZInteractionComponent* GetInteractionComponentInterface() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface|Interaction")
	void InteractionPerformInterface();
};
