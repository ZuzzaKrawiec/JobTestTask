// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ZZInteractionManagerComponent.generated.h"

class UZZInteractionComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionComponentRegistered, UZZInteractionComponent*, InInteractionComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionComponentUnregistered, UZZInteractionComponent*, InInteractionComponent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZUZANNAKRAWIEC_API UZZInteractionManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UZZInteractionManagerComponent();

	void RegisterInteractionComponent(UZZInteractionComponent* InInteractionComponent);
	void UnregisterInteractionComponent(UZZInteractionComponent* InInteractionComponent);
	const TSet<UZZInteractionComponent*>& GetRegisteredInteractionComponents() const;

	UPROPERTY(BlueprintAssignable /*BlueprintCallable*/)
	FOnInteractionComponentRegistered OnInteractionComponentRegistered;
	UPROPERTY(BlueprintAssignable /*BlueprintCallable*/)
	FOnInteractionComponentUnregistered OnInteractionComponentUnregistered;
protected:
	UPROPERTY(BlueprintReadWrite)
	TSet<UZZInteractionComponent*> RegisteredInteractionComponents;
};
