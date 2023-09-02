// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ZZPawn.h"

// Sets default values
AZZPawn::AZZPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZZPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZZPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZZPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

