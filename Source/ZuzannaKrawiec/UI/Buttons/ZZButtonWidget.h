// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

#include "ZZButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonPressed, UZZButtonWidget*, InPressedButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonHovered, UZZButtonWidget*, InPressedButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonUnhovered, UZZButtonWidget*, InPressedButton);

/**
 * 
 */
UCLASS()
class ZUZANNAKRAWIEC_API UZZButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ButtonText;

	virtual void ReflectData();
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UButton* Button;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnButtonPressed OnButtonPressed;
	UFUNCTION()
	void OnButtonPressedCallback();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnButtonHovered OnButtonHovered;
	UFUNCTION()
	void OnButtonHoveredCallback();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnButtonUnhovered OnButtonUnhovered;
	UFUNCTION()
	void OnButtonUnhoveredCallback();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Button Settings")
	FText TextOnButton;

protected:
	virtual void NativeConstruct();
	virtual void NativePreConstruct();

};
