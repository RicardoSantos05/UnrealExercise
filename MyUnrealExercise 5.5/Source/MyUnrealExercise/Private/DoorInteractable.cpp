#include "DoorInteractable.h"
#include "Engine/Engine.h"

ADoorInteractable::ADoorInteractable()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADoorInteractable::Interact_Implementation(AActor* Interactor)
{
    // Usar a função Execute_Interact
    IMyDoorInterface::Execute_Interact(this, Interactor);

    // Ou o código do que deves fazer aqui (abrir porta, por exemplo)
    UE_LOG(LogTemp, Warning, TEXT("A porta foi interagida por %s"), *GetNameSafe(Interactor));
}