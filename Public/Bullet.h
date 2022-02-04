// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class WEEK5SESSION_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(EditAnywhere, Category = "bulletThings")
	float Speed = 1000.f;

	UPROPERTY(EditAnywhere, Category = "bulletThings")
	float TimeBeforeDestroy = 5.f;

	UPROPERTY(EditAnywhere, Category = "bulletThings")
	float TimeLived = 0.f;

	UPROPERTY(EditAnywhere, Category = "bulletThings")
	UParticleSystem* BulletFireFX = nullptr;

	UPROPERTY(EditAnywhere, Category = "bulletThings")
	USoundBase* BulletFireSound= nullptr;

//int score;

UFUNCTION()
void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
