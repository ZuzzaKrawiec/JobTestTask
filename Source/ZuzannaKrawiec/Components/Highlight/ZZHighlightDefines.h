// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ZZHighlightDefines.generated.h"

UENUM(Blueprintable)
enum class EHighlightFlag : uint8
{
	Action,
	Hovered
};