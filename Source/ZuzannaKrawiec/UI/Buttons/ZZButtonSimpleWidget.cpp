// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Buttons/ZZButtonSimpleWidget.h"
#include "Components/Interaction/ZZInteractionComponent.h"
#include "Components/Interaction/ZZInteractionDefines.h"


void UZZButtonSimpleWidget::SetData(UZZInteractionComponent* InInteractionComponent)
{
	InteractionComponent = InInteractionComponent;

	if (!InteractionComponent)
	{
		return;
	}
	FInteractionData* Data = InteractionComponent->FindInteractionData();
	if (!Data)
	{
		return;
	}
	ButtonText->SetText(Data->Name);
	ButtonText->SetToolTipText(Data->Desc);
	ButtonText->SetColorAndOpacity(Data->Color);
}
UZZInteractionComponent* UZZButtonSimpleWidget::GetInteractionComponent() const
{
	return InteractionComponent;
}