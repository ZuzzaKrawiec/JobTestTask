// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "Components/Interaction/ZZInteractionDefines.h"
#include "ZZInteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZUZANNAKRAWIEC_API UZZInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UZZInteractionComponent();

	void RegisterInteractionComponent();
	void UnregisterInteractionComponent();

	void StartInteraction(AActor* InCallingActor);
	void StopInteraction(AActor* InCallingActor);
	void UseInteraction(AActor* InCallingActor, bool bState);

	const FDataTableRowHandle& GetInteractionDataRow() const;
	FInteractionData* FindInteractionData();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type Reason) override;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AOE Effect", meta = (DataTable = "/Game/DataTable/DT_Interactions.DT_Interactions"))
	FDataTableRowHandle InteractionDataRow;
};
