#include "AlternativeCPlusPlus.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DoorInteractable.h"

AAlternativeCPlusPlus::AAlternativeCPlusPlus()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
}

void AAlternativeCPlusPlus::BeginPlay()
{
	Super::BeginPlay();
}

void AAlternativeCPlusPlus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Start = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	FVector End = Start + (Forward * 200.0f);

	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	float Radius = 50.f; // <- aumenta este valor para uma margem maior
	bool bHit = GetWorld()->SweepSingleByChannel(
		Hit,
		Start,
		End,
		FQuat::Identity,
		ECC_Visibility,
		FCollisionShape::MakeSphere(Radius),
		Params
	);

	CurrentLookTarget = bHit ? Hit.GetActor() : nullptr;

	// Mostra esfera de debug (para veres a deteção)
	DrawDebugSphere(GetWorld(), bHit ? Hit.ImpactPoint : End, Radius, 12, bHit ? FColor::Red : FColor::Green, false, 0.1f);
}

void AAlternativeCPlusPlus::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AAlternativeCPlusPlus::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAlternativeCPlusPlus::MoveRight);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AAlternativeCPlusPlus::Interact);
}

void AAlternativeCPlusPlus::MoveForward(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AAlternativeCPlusPlus::MoveRight(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AAlternativeCPlusPlus::Interact()
{
	if (CurrentLookTarget)
	{
		ADoorInteractable* Door = Cast<ADoorInteractable>(CurrentLookTarget);
		if (Door)
		{
			Door->Interact(this); // Chama a função da interface na porta
		}
	}
}