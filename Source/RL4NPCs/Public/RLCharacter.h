// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "RLCharacter.generated.h"

UCLASS(Blueprintable)
class RL4NPCS_API ARLCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARLCharacter();

	// Make a health property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		float health = 100;

	// Make an isDead property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "RL Character") 
		bool isDead = false;

	// Calculate death function (helper) -- tells you whether isDead should be true or false
	virtual void CalculateDead();

	// Calculate health function
	UFUNCTION(BlueprintCallable, Category = "RL Character")
		virtual void CalculateHealth(float delta);

#if WITH_EDITOR
	// Editor-centric code for changing properties
	virtual void PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent) override;
#endif

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
