// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ZZHUD.h"
#include "Components/MenuManager/ZZMenuManagerComponent.h"
#include "Settings/ZZUISettings.h"


AZZHUD::AZZHUD()
{
	PrimaryActorTick.bCanEverTick = false;
	MenuManagerComponent = CreateDefaultSubobject<UZZMenuManagerComponent>(FName("Menu Manager Component"));
	MenuManagerComponent->bEditableWhenInherited = true;
}


void AZZHUD::OpenMenu(EMenuType InMenuType)
{
	if (!MenuManagerComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZHUD::OpenMenu MenuManagerComponent is null"));
		return;
	}
	TSoftClassPtr<UZZMenuWidget> MenuWidgetClass = *GetDefault<UZZUISettings>()->MenuWidgetClass.Find(InMenuType);
	if (MenuWidgetClass.IsNull())
	{
		UE_LOG(LogTemp, Warning, TEXT("AZZHUD::OpenMenu menu widget class missing data"));
		return;
	}
	MenuManagerComponent->OpenMenu(MenuWidgetClass.LoadSynchronous());
}