// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/ZZMenuWidget.h"

#include "Components/HorizontalBox.h"

#include "ZZMenuMainWidget.generated.h"

class UZZInteractionComponent;
/**
 * 
 */
UCLASS()
class ZUZANNAKRAWIEC_API UZZMenuMainWidget : public UZZMenuWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UHorizontalBox* Interactions;

	void GenerateInteraction();
	UFUNCTION()
	void AddInteraction(UZZInteractionComponent* InInteractionComponent);
	UFUNCTION()
	void RemoveInteraction(UZZInteractionComponent* InInteractionComponent);

	UFUNCTION()
	void OnButtonPressed(UZZButtonWidget* InButton);

	UFUNCTION()
	void OnButtonHovered(UZZButtonWidget* InButton);

	UFUNCTION()
	void OnButtonUnhovered(UZZButtonWidget* InButton);
	void SetHighlightForButton(UZZButtonWidget* InButton, EHighlightFlag InFlag, bool bState);

	void FindInteractionManager();

	void OpenWaitMenu();
private:
	virtual void NativeConstruct();
	virtual void NativeDestruct();

	UPROPERTY()
	UZZInteractionManagerComponent* CachedInteractionManagerComponent = nullptr;

	TArray<UZZButtonSimpleWidget*> InteractionsList;
};
