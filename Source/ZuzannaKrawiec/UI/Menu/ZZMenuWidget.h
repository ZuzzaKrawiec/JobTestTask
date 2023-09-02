// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "ZZMenuDefines.h"

#include "ZZMenuWidget.generated.h"


/**
 * 
 */
UCLASS()
class ZUZANNAKRAWIEC_API UZZMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:

	UFUNCTION(BlueprintCallable, Category="Widget|Menu Manager")
	void OpenMenu(TSubclassOf<UZZMenuWidget> InMenuWidgetClass);

	UFUNCTION(BlueprintCallable, Category = "Widget|Menu Manager")
	void CloseMenu();

	FOnMenuOpen OnMenuOpen;
	FOnMenuClose OnMenuClose;
};
