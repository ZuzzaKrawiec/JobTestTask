// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/Interaction/ZZInteractionInterface.h"
#include "Components/Highlight/ZZHightlightInterface.h"
#include "Components/Highlight/ZZHighlightDefines.h"

#include "ZZBuildingActor.generated.h"

class UZZInteractionComponent;
class UZZHighlightComponent;

UCLASS()
class ZUZANNAKRAWIEC_API AZZBuildingActor : public AActor, public IZZInteractionInterface, public IZZHightlightInterface
{
	GENERATED_BODY()
	
public:	
	AZZBuildingActor();

	/*Interaction Interaface*/
	UZZInteractionComponent* GetInteractionComponentInterface_Implementation() const;
	void InteractionPerformInterface_Implementation();

	/*Highlight Interface*/
	void SetHighlight_Implementation(EHighlightFlag InFlag, bool bState);

	/*Geters / Seters*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Interaction")
	UZZInteractionComponent* GetInteractionComponent() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Interaction")
	UStaticMeshComponent* GetStaticMeshComponent() const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interaction")
	UZZInteractionComponent* InteractionComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	UZZHighlightComponent* HighlightComponent = nullptr;
};
