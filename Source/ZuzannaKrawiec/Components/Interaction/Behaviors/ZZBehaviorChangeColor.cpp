// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Interaction/Behaviors/ZZBehaviorChangeColor.h"
#include "Kismet/KismetMathLibrary.h"


void UZZBehaviorChangeColor::BehaviorStartExecute(AActor* InCallingActor)
{
	Super::BehaviorStartExecute(InCallingActor);
	BehaviorAction(InCallingActor);
}
void UZZBehaviorChangeColor::BehaviorStopExecute(AActor* InCallingActor)
{
	Super::BehaviorStopExecute(InCallingActor);
}
void UZZBehaviorChangeColor::BehaviorAction_Implementation(AActor* InCallingActor)
{
	if (Materials.Num() <= 0)
	{
		return;
	}
	TArray<UActorComponent*> OutComponents;
	InCallingActor->GetComponents(OutComponents, true);

	for (UActorComponent* ActorComponent : OutComponents)
	{
		UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(ActorComponent);
		if (!PrimitiveComponent)
		{
			continue;
		}
		for (int32 i = 0; i < PrimitiveComponent->GetNumMaterials(); i++)
		{
			PrimitiveComponent->SetMaterial(i, Materials[UKismetMathLibrary::RandomInteger(Materials.Num())]);
		}
	}
}