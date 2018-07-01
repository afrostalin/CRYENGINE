// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include "IPlatformUser.h"
#include "IPlatformAccount.h"

namespace Cry
{
	namespace GamePlatform
	{
		//! Standard implementation of a game platform user.
		class CUser final : public IUser
		{
		public:
			explicit CUser(IAccount& account, const DynArray<IAccount*>& connectedAccounts);
			virtual ~CUser();

			// IUser
			virtual const char* GetNickname() const override;
			virtual UserIdentifier GetIdentifier() const override;

			virtual void SetStatus(const char* status) override;
			virtual const char* GetStatus() const override;

			virtual ITexture* GetAvatar(EAvatarSize size) const override;
			virtual IAccount* GetAccount(const ServiceIdentifier& svcId) const override;
			// ~IUser

		protected:
			IAccount& m_mainAccount;
			DynArray<IAccount*> m_connectedAccounts;
		};
	}
}