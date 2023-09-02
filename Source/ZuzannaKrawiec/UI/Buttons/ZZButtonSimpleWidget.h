// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Buttons/ZZButtonWidget.h"
#include "ZZButtonSimpleWidget.generated.h"

class UZZInteractionComponent;
/**
 * 
 */
UCLASS()
class ZUZANNAKRAWIEC_API UZZButtonSimpleWidget : public UZZButtonWidget
{
	GENERATED_BODY()

public:
	void SetData(UZZInteractionComponent* InInteractionComponent);
	UZZInteractionComponent* GetInteractionComponent() const;

protected:
	UPROPERTY()
	UZZInteractionComponent* InteractionComponent;


};
