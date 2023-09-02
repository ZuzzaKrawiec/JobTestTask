// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "UI/Menu/ZZMenuDefines.h"
#include "ZZUISettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig, BlueprintType)
class ZUZANNAKRAWIEC_API UZZUISettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(config, EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TMap<EMenuType, TSoftClassPtr<class UZZMenuWidget>> MenuWidgetClass;

	UPROPERTY(config, EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSoftClassPtr<class UZZButtonSimpleWidget> SimpleButtonWidgetClass;
};
