// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MenuManager/ZZMenuManagerComponent.h"
#include "UI/Menu/ZZMenuWidget.h"
#include "UI/Menu/ZZMenuDefines.h"
#include "Kismet/GameplayStatics.h"

UZZMenuManagerComponent::UZZMenuManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UZZMenuManagerComponent::OpenMenu(TSubclassOf<UZZMenuWidget> InMenuWidgetClass)
{
	MenuRelease();
	if (!InMenuWidgetClass)
	{
		UE_LOG(MenuManager, Warning, TEXT("UZZMenuManagerComponent::OpenMenu - Missing widget class"));
		return;
	}

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (!PlayerController)
	{
		UE_LOG(MenuManager, Warning, TEXT("UZZMenuManagerComponent::OpenMenu - Missing player controller"));
		return;
	}

	UZZMenuWidget* MenuWidgetCreated = CreateWidget<UZZMenuWidget>(PlayerController, InMenuWidgetClass);
	if (!MenuWidgetCreated)
	{
		UE_LOG(MenuManager, Warning, TEXT("UZZMenuManagerComponent::OpenMenu - Create widget failed"));
		return;
	}
	MenuWidgetCreated->AddToViewport(0);
	MenuWidgetCreated->OnMenuOpen.BindUObject(this, &UZZMenuManagerComponent::OpenMenu);
	MenuWidgetCreated->OnMenuClose.BindUObject(this, &UZZMenuManagerComponent::CloseMenu);
	SetMenuWidgetOpened(MenuWidgetCreated);
}
void UZZMenuManagerComponent::CloseMenu()
{
	MenuRelease();
}
void UZZMenuManagerComponent::MenuRelease()
{
	if (!GetMenuWidgetOpened())
	{
		UE_LOG(MenuManager, Warning, TEXT("UZZMenuManagerComponent::MenuRelease - no menu opened"));
		return;
	}
	GetMenuWidgetOpened()->OnMenuClose.Unbind();
	GetMenuWidgetOpened()->OnMenuOpen.Unbind();
	GetMenuWidgetOpened()->RemoveFromParent();
}

void UZZMenuManagerComponent::SetMenuWidgetOpened(UZZMenuWidget* InMenuWidgetOpened)
{
	MenuWidgetOpened = InMenuWidgetOpened;
}
UZZMenuWidget* UZZMenuManagerComponent::GetMenuWidgetOpened() const
{
	return MenuWidgetOpened;
}