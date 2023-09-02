// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

class UZZMenuWidget;

DECLARE_LOG_CATEGORY_EXTERN(MenuManager, Log, All);

DECLARE_DELEGATE_OneParam(FOnMenuOpen, TSubclassOf<UZZMenuWidget> InMenuWigdetClass);
DECLARE_DELEGATE(FOnMenuClose);

UENUM(BlueprintType, Blueprintable)
enum class EMenuType : uint8
{
	None,
	MainMenu,
	WaitMenu
};