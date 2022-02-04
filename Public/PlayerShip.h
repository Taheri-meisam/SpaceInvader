// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerShip.generated.h"

UCLASS()
class WEEK5SESSION_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
UStaticMeshComponent* PlayerMesh = nullptr;

UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
USpringArmComponent* SpringArm {nullptr};
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
UCameraComponent* Camera = nullptr;

UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
float Speed = 5.f;

UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
int Ammo = 30;

UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
USoundBase* ShootingSound = nullptr;

UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
USoundBase* ReloadingSound = nullptr;

UPROPERTY(EditAnywhere, meta =(AllowPrivateAccess = "true"));
TSubclassOf<AActor> ActorToSpawn;

void Reload();

void Shoot();




UFUNCTION(BlueprintCallable)
void ResetLocation() const;
bool InContact;

private:
FVector InitLocation = FVector::ZeroVector;


void MoveXAxis(float Value);
void MoveYAxis(float Value);

void Dash();
float XValue = 0.f;
float YValue = 0.f;
float DashTimer = 0.f;



};

