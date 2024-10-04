#pragma once
namespace Game
{
	class Player;
	class BackGround;
	class Monster;
	class CollisionFunc
	{
	public:
		virtual void EnterCollision(Player* const obj);
		virtual void OnCollision(Player* const obj);
		virtual void ExitCollision(Player* const obj);

		virtual void EnterCollision(BackGround* const obj);
		virtual void OnCollision(BackGround* const obj);
		virtual void ExitCollision(BackGround* const obj);

		virtual void EnterCollision(Monster* const obj);
		virtual void OnCollision(Monster* const obj);
		virtual void ExitCollision(Monster* const obj);
	};
}


