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

	// The current health of the character
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		float health = 100;

	// Does the character have the flag?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool hasFlag = false;

	// Does the character hear noise?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool hearsNoise = false;

	// Does the character see an enemy?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool seeEnemy = false;

	// Is the character bumping into anything?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool bumping = false;

	// Is the character taking damage?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool takingDamage = false;

	// Is the character moving?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool moving = false;

	// Distance to the enemy
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		float enemyDistance = 0.0;

	// Is the character dead?
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
