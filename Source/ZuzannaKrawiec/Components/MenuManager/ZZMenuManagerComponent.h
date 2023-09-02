// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ZZMenuManagerComponent.generated.h"

class UZZMenuWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZUZANNAKRAWIEC_API UZZMenuManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UZZMenuManagerComponent();

	UFUNCTION(BlueprintCallable, Category = "Widget|Menu Manager")
	void OpenMenu(TSubclassOf<UZZMenuWidget> InMenuWidgetClass);
	
	UFUNCTION(BlueprintCallable, Category = "Widget|Menu Manager")
	void CloseMenu();

	void MenuRelease();

	UFUNCTION(BlueprintCallable, Category = "Widget|Menu Manager")
	void SetMenuWidgetOpened(UZZMenuWidget* InMenuWidgetOpened);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Widget|Menu Manager")
	UZZMenuWidget* GetMenuWidgetOpened() const;
protected:

	UPROPERTY()
	UZZMenuWidget* MenuWidgetOpened = nullptr;
};
