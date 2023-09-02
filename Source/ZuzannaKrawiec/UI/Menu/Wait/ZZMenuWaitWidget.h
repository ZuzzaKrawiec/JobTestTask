// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/ZZMenuWidget.h"
#include "UI/Buttons/ZZButtonWidget.h"
#include "ZZMenuWaitWidget.generated.h"

/**
 * 
 */
UCLASS()
class ZUZANNAKRAWIEC_API UZZMenuWaitWidget : public UZZMenuWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UZZButtonWidget* ButtonAbort;

	UFUNCTION()
	void AbortAction(UZZButtonWidget* InButton);

protected:
	virtual void NativeConstruct() override;
};
