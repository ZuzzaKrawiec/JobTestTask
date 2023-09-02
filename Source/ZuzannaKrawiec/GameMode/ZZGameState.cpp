// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ZZGameState.h"


AZZGameState::AZZGameState()
{
	InteractionManagerComponent = CreateDefaultSubobject<UZZInteractionManagerComponent>(FName("Interaction Manager Component"));
}
UZZInteractionManagerComponent* AZZGameState::GetInteractionManagerComponent() const
{
	return InteractionManagerComponent;
}