#pragma once

#include "FlipbookActor.h"

class Flipbook;
class Collider;
class BoxCollider;

enum class PlayerState
{
	Idle,
	Move,
	Skill
};

class Player : public FlipbookActor
{
	using Super = FlipbookActor;
public:
	Player();
	virtual ~Player() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

private:

	virtual void TickIdle();
	virtual void TickMove();
	virtual void TickSkill();

	void SetState(PlayerState state);	// state 바꿀 때 함수로 만들어서 사용하기 - 무작정 _state = PlayerState::MoveGround; 이렇게 작성하지 말라는 것! 디버깅할 때 이 함수에 중단점만 걸면 다 걸림
	void SetDir(Dir dir);

	void UpdateAnimation();

	bool HasReachedDest();
	bool CanGo(Vec2Int cellPos);
	void SetCellPos(Vec2Int cellPos, bool teleport = false);

private:
	Flipbook* _flipbookIdle[4] = {};
	Flipbook* _flipbookMove[4] = {};
	Flipbook* _flipbookAttack[4] = {};

	Vec2Int _cellPos = {};
	Vec2 _speed = {};
	Dir _dir = DIR_DOWN;
	PlayerState _state = PlayerState::Idle;
	bool _keyPressed = false;
};

