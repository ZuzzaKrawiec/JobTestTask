// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Menu/ZZMenuWidget.h"


void UZZMenuWidget::OpenMenu(TSubclassOf<UZZMenuWidget> InMenuWidgetClass)
{
	OnMenuOpen.ExecuteIfBound(InMenuWidgetClass);
}

void UZZMenuWidget::CloseMenu()
{
	OnMenuClose.ExecuteIfBound();
}
