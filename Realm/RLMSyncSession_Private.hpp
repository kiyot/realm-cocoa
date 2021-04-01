////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import "RLMSyncSession.h"

#import "RLMSyncUtil_Private.h"
#import <memory>

namespace realm {
class AsyncOpenTask;
class SyncSession;
}

NS_ASSUME_NONNULL_BEGIN

@interface RLMSyncSession () {
@public     // So it's visible to tests
    std::weak_ptr<realm::SyncSession> _session;
} RLM_SYNC_UNINITIALIZABLE

- (instancetype)initWithSyncSession:(std::shared_ptr<realm::SyncSession> const&)session;

@end

@interface RLMSyncErrorActionToken ()

- (instancetype)initWithOriginalPath:(std::string)originalPath;

@end

@interface RLMAsyncOpenTask ()
@property (nonatomic) std::shared_ptr<realm::AsyncOpenTask> task;
@end

NS_ASSUME_NONNULL_END
