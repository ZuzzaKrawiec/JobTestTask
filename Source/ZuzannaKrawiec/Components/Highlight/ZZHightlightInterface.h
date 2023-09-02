// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ZZHighlightDefines.h"
#include "ZZHightlightInterface.generated.h"

UINTERFACE(MinimalAPI)
class UZZHightlightInterface : public UInterface
{
	GENERATED_BODY()
};

class ZUZANNAKRAWIEC_API IZZHightlightInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Highlight")
	void SetHighlight(EHighlightFlag InFlag, bool bState);
};
