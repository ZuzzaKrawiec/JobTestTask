// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Engine/DataTable.h"
#include "Styling/SlateTypes.h"
#include "ZZInteractionDefines.generated.h"

USTRUCT()
struct FInteractionData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FInteractionData() {};

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Interaction|Details")
	FText Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction|Details")
	FText Desc;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction|Details")
	FSlateColor Color;

};