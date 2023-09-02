// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZZHighlightDefines.h"
#include "Components/ActorComponent.h"
#include "ZZHighlightComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZUZANNAKRAWIEC_API UZZHighlightComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	virtual void SetHighlight(EHighlightFlag InFlag, bool bState);
	virtual void UpdateHighlight(bool bState);
	void AddFlag(EHighlightFlag InFlag);
	void RemoveFlag(EHighlightFlag InFlag);
	void SetFlag(EHighlightFlag InFlag, bool bState);
	

private:
	int32 HightlightState = 0;
};
