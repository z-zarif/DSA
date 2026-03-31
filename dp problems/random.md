

## Inspiration

There's a scene in `The Big Short` where Ryan Gosling looks directly into the camera and explains mortgage-backed securities using Jenga blocks. And the entire audience — smart, educated adults — finally understands how the global financial system works. For the first time. During a *movie*. About a crisis that already happened.

>> `That's the problem.`

We're from Bangladesh. A beautiful, resilient, chaotic country where your financial future can be derailed by a corrupt minister's nephew, a multinational corporation lobbying for a policy that helps them and hurts everyone else, or just the general vibe of "nobody told me money worked like that." We grew up watching adults — smart, hardworking adults — get financially blindsided not because they were foolish, but because nobody ever sat them down and said: *here's how money moves, here's how economies work, here's how not to get played.*

And if that's the reality for adults, imagine what it's like for kids.

Across South Asia, financial literacy isn't just underprioritized in schools — in many places, it's completely invisible. Children are taught to study hard, get a job, and trust the system. What they're not taught is how the system actually works — who benefits from their ignorance, and what power they could have if they understood it.

We didn't want to write a research paper about this. We wanted to *do something about it.*

So we built Nexus — a micro-economy sandbox that puts kids in the driver's seat of a living, breathing economy. Because the best time to learn about money is before someone takes yours.

As a great philosopher once said: *"Winter is coming."* We just wanted the next generation to actually be prepared for it.

---

## What It Does

#### `Nexus` is a browser-based micro-economy simulator designed to teach children and teenagers the fundamentals of financial literacy through *doing*, not *reading*.

When a student opens Nexus, they don't see a textbook. They see a dashboard that looks and feels like a real fintech product — because we deliberately designed it that way. They have a wallet, a portfolio, a marketplace, and real decisions to make.

Here's what the world of Nexus looks like:

**The Marketplace** is where kids can post services — think "I'll debug your code for ৳150" or "I'll design your logo for ৳300." They set their price, list their skill, and wait. If the market doesn't respond, they learn something invaluable: pricing matters, and the world doesn't owe you customers. If it does respond, they learn something even better: your skills have real monetary value.

**The Equity Exchange** is a simulated stock market featuring startups. Kids can buy and sell shares, watch valuations fluctuate, and experience firsthand the emotional rollercoaster of seeing your portfolio go green, then red, then hopefully green again. It teaches risk tolerance, the concept of investment, and — most importantly — that money can work *for* you, not just the other way around.

**The Talent Hub** flips the script entirely: instead of selling, kids are now *hiring*. They browse skill profiles, evaluate candidates, and make recruitment decisions — learning that building something bigger than yourself requires understanding other people's value.

All of this is denominated in Bangladeshi Taka (৳), which is a deliberate choice. Abstract numbers in a fictional currency teach abstract lessons. Real currency — *your* currency, the one your parents use, the one you'll use — makes it personal.

Oh, and there's a savings goal tracker. Because compound interest might be the most powerful force in the universe, and literally nobody tells kids about it until it's too late.

---

## How We Built It

Pure HTML, CSS, and JavaScript. No frameworks, no backend, no database, no dependencies. Just three files and a dream.

We made this choice intentionally. We wanted Nexus to be accessible anywhere — on a slow connection, on a cheap device, in a school with limited IT infrastructure. If you have a browser, you have Nexus. That's the whole point.

The UI was designed to feel like a real product — not a kids' app with cartoon coins bouncing around. We used Inter as our typeface, a clean dark-themed dashboard aesthetic, and component design patterns borrowed from actual fintech interfaces. We wanted students to feel like they were using something *real*, because they are being taken seriously, and the design needed to communicate that.

We beta tested the platform at the middleSchool right next to one of our houses. Yes, a *middleschool*. We ran observation sessions, collected surveys, watched kids interact with the interface, and took notes on where they got confused, where they got excited, and where they immediately tried to buy stocks in something called "CoolCo" without reading any of the details. (Relatable, honestly.)

We iterated based on that feedback, adjusted the UI for younger users, simplified certain flows, and made sure the core experience remained genuinely engaging rather than educational in that soul-crushing, worksheet-energy kind of way.

---

## Challenges We Ran Into

Where do we begin.

**Making it child-friendly without making it childish** was the central tension of the entire project. Our instinct as developers was to add complexity — more features, more data, more realism. But every time we sat with the kids at the middleschool, we realized that clarity beat cleverness every single time. We had to unlearn a lot of our own assumptions about what an "impressive" product looks like.

**The bug.** Oh, the bug. We have to tell you about the bug.

We spent approximately four hours — *four hours* — trying to figure out why the savings goal progress bar wasn't updating correctly when a user bought stocks. Four hours of console.log debugging, staring at the DOM, questioning our life choices, and genuinely wondering if we had accidentally broken the laws of JavaScript. We even briefly considered that maybe the browser itself was wrong.

It was a typo. One variable was named `goalTarget` in one place and `goalTargetAmount` in another. Four hours. One letter difference. We are fine. We have moved on. We do not think about it anymore.

This is what it means to be a developer: you will feel like Tony Stark building the Iron Man suit in a cave, and then you will spend four hours on a typo. Both things are true simultaneously.

There were also genuine UX challenges around making the stock market feel dynamic without a real backend — we had to simulate price fluctuations client-side in a way that felt organic rather than random. Getting that balance right took multiple iterations.

---

## Accomplishments That We're Proud Of

We're proud that we built something that *works* — fully functional, deployable, and usable by a real child today, right now, without any setup.

We're proud of the beta testing process. Going into a middleschool, watching actual children interact with something you built, and seeing a kid excitedly post their first "service" on the Talent Hub — that's a feeling no hackathon submission form can fully capture.

We're proud that it's denominated in Taka. That might sound small, but it's not. It's a statement that financial education for South Asian kids deserves to be *about* South Asian kids, not a re-skinned version of something built for someone else's context.

We're proud that the whole thing runs in three files. There's something deeply satisfying about that.

And honestly? We're proud that we started from a place of genuine frustration — with corrupt systems, with economic helplessness, with a generation of kids being set up to not understand the world they're inheriting — and we turned that frustration into something constructive. That's not nothing.

---

## What We Learned

We learned that financial literacy isn't just an educational gap — it's a *power* gap. When people don't understand how money works, someone else gets to make decisions for them. Teaching kids economics isn't just pedagogy. It's a political act.

We learned that HTML, CSS, and JavaScript are genuinely powerful enough to build something meaningful. You don't always need a framework. Sometimes you need clarity of vision more than you need React.

We learned that children are not simple users — they are *brutally honest* ones. They will immediately tell you when something is confusing, boring, or doesn't make sense. Every UX insight we got from the middleschool beta was sharper than anything we generated on our own.

We learned that the best products are built from real problems. Not from "what would be a cool feature" but from "what would have helped someone I know." That's the energy Nexus was built with, and we think you can feel it in the product.

And we learned about typos. God, did we learn about typos.

---

## What's Next for Micro Economy Simulator

The version you're seeing today is a foundation. What we're imagining next is a movement.

**Multiplayer economies.** The real power of Nexus is when students are trading with each other — not a simulation, but each other. Real negotiation. Real peer-to-peer marketplaces. Real consequences when you overprice your service or undervalue your skills. We want to build classroom-scale economies where an entire class is one interconnected market.

**Curriculum integration.** We're in conversations about partnering with schools across Bangladesh to embed Nexus into their existing timetables — not as an extra, but as the *primary vehicle* for teaching economics. A one-link classroom tool that requires no training and no installation.

**Localization across South Asia.** The currency changes. The context changes. The fundamental problem doesn't. We want Nexus running in Indian rupees, Pakistani rupees, Sri Lankan rupees, Nepali rupees — wherever kids are growing up in a system that hasn't equipped them to navigate it.

**AI-powered financial coaching.** Imagine a friendly AI companion that watches your in-game decisions and says: *"Hey, you've been spending 80% of your wallet on stock speculation without any diversification — want to talk about what that strategy looks like long term?"* Not a lecture. A conversation. That's the future we're building toward.

**The long game** is this: a generation of South Asian kids who grow up understanding money, understanding markets, and understanding that their economic future is not something that happens *to* them — it's something they can shape. That's what Nexus is really about. Not the progress bar, not the stock grid, not the Talent Hub.

Agency. For kids who deserve it.

*"You either die a financially illiterate hero, or you live long enough to understand compound interest."*
— Probably Batman, if Batman grew up in Dhaka.

---
