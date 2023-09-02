// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Menu/ZZMenuDefines.h"
#include "ZZHUD.generated.h"

class UZZMenuManagerComponent;
/**
 * 
 */
UCLASS()
class ZUZANNAKRAWIEC_API AZZHUD : public AHUD
{
	GENERATED_BODY()

public:
	
	AZZHUD();

	void OpenMenu(EMenuType InMenuType);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Widget|Menu Manager")
	UZZMenuManagerComponent* GetMenuManagerComponent();

protected:
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Widget|Menu Manager")
	UZZMenuManagerComponent* MenuManagerComponent = nullptr;
};
inline UZZMenuManagerComponent* AZZHUD::GetMenuManagerComponent()
{
	return MenuManagerComponent;
}