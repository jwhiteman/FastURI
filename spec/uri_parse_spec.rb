require "spec_helper"

describe URIParse do
  describe "#parse" do
    it "parses relative netpaths" do
      res = URIParse.parse("//foo-bar-baz")

      expect(res[:uri]).to eq("//foo-bar-baz")
    end

    it "parses relative netpaths with domain labels" do
      res = URIParse.parse("//foo.bar.baz-buzz")

      expect(res[:uri]).to eq("//foo.bar.baz-buzz")
    end

    it "parses relative netpaths with a final dot" do
      res = URIParse.parse("//foo-bar-baz.")

      expect(res[:uri]).to eq("//foo-bar-baz.")
    end

    it "parses relative netpaths with an ipv4 address" do
      res = URIParse.parse("//192.168.1.1")

      expect(res[:uri]).to eq("//192.168.1.1")
    end

    it "parses relative netpath with an optional port" do
      res = URIParse.parse("//192.168.1.1:3000")

      expect(res[:uri]).to eq("//192.168.1.1:3000")
    end

    it "parses relative netpath with an optional port and userinfo" do
      res = URIParse.parse("//john-doe@192.168.1.1:3000")

      expect(res[:uri]).to eq("//john-doe@192.168.1.1:3000")
    end

    it "parses relative netpath with an empty server" do
      res = URIParse.parse("//")

      expect(res[:uri]).to eq("//")
    end

    it "parses relative netpath with a reg_name authority" do
      res = URIParse.parse("//somename")

      expect(res[:uri]).to eq("//")
    end
  end
end

