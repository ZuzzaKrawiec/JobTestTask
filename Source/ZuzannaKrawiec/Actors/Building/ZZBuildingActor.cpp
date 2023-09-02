// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Building/ZZBuildingActor.h"
#include "Components/Highlight/ZZHighlightComponent.h"
#include "Components/Interaction/ZZInteractionComponent.h"

AZZBuildingActor::AZZBuildingActor()
{
	PrimaryActorTick.bCanEverTick = false;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("Building Mesh"));
	StaticMeshComponent->bEditableWhenInherited = true;
	InteractionComponent = CreateDefaultSubobject<UZZInteractionComponent>(FName("Interaction Component"));
	InteractionComponent->bEditableWhenInherited = true;

	HighlightComponent = CreateDefaultSubobject<UZZHighlightComponent>(FName("Highlight Component"));
	HighlightComponent->bEditableWhenInherited = true;

	RootComponent = StaticMeshComponent;
}

void AZZBuildingActor::BeginPlay()
{
	Super::BeginPlay();
}


UZZInteractionComponent* AZZBuildingActor::GetInteractionComponentInterface_Implementation() const
{
	return GetInteractionComponent();
}
void AZZBuildingActor::InteractionPerformInterface_Implementation()
{
}

void AZZBuildingActor::SetHighlight_Implementation(EHighlightFlag InFlag, bool bState)
{
	if (!HighlightComponent)
	{
		return;
	}
	HighlightComponent->SetHighlight(InFlag, bState);
}
UZZInteractionComponent* AZZBuildingActor::GetInteractionComponent() const
{
	return InteractionComponent;
}

UStaticMeshComponent* AZZBuildingActor::GetStaticMeshComponent() const
{
	return StaticMeshComponent;
}