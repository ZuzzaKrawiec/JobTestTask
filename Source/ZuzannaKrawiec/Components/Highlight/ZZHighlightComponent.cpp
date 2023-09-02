// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Highlight/ZZHighlightComponent.h"

void UZZHighlightComponent::SetHighlight(EHighlightFlag InFlag, bool bState)
{
	bool OldState = (HightlightState != 0);
	SetFlag(InFlag, bState);
	bState = (HightlightState != 0);

	if (bState == OldState)
	{
		return;
	}
	UpdateHighlight(bState);
}
void UZZHighlightComponent::UpdateHighlight(bool bState)
{
	TArray<UActorComponent*> OutComponents;
	GetOwner()->GetComponents(OutComponents, true);
	for (UActorComponent* Component : OutComponents)
	{
		UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(Component);
		if (!PrimitiveComponent)
		{
			continue;
		}
		PrimitiveComponent->SetCustomPrimitiveDataFloat(0, bState ? 5.0f : 0.0f);
	}
}
void UZZHighlightComponent::AddFlag(EHighlightFlag InFlag)
{
	HightlightState |= 1 << uint8(InFlag);
}
void UZZHighlightComponent::RemoveFlag(EHighlightFlag InFlag)
{
	HightlightState &= ~(1<<uint8(InFlag));
}

void UZZHighlightComponent::SetFlag(EHighlightFlag InFlag, bool bState)
{
	if (bState)
	{
		AddFlag(InFlag);
	}
	else
	{
		RemoveFlag(InFlag);
	}
}