// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Buttons/ZZButtonWidget.h"


void UZZButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();
	Button->OnPressed.AddDynamic(this, &UZZButtonWidget::OnButtonPressedCallback);
	Button->OnHovered.AddDynamic(this, &UZZButtonWidget::OnButtonHoveredCallback);
	Button->OnUnhovered.AddDynamic(this, &UZZButtonWidget::OnButtonUnhoveredCallback);
	ReflectData();
}
void UZZButtonWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	ReflectData();
}


void UZZButtonWidget::ReflectData()
{
	ButtonText->SetText(TextOnButton);
}
void UZZButtonWidget::OnButtonPressedCallback()
{
	OnButtonPressed.Broadcast(this);
}
void UZZButtonWidget::OnButtonHoveredCallback()
{
	OnButtonHovered.Broadcast(this);
}
void UZZButtonWidget::OnButtonUnhoveredCallback()
{
	OnButtonUnhovered.Broadcast(this);
}