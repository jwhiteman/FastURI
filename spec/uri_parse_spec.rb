require "spec_helper"

describe URIParse do
  describe "#parse" do
    it "parses relative netpaths" do
      res = URIParse.parse("//foo-bar-baz")

      expect(res).to eq({uri: "//foo-bar-baz"})
    end

    it "parses relative netpaths with domain labels" do
      res = URIParse.parse("//foo.bar.baz-buzz")

      expect(res).to eq({uri: "//foo.bar.baz-buzz"})
    end

    it "parses relative netpaths with a final dot" do
      res = URIParse.parse("//foo-bar-baz.")

      expect(res).to eq({uri: "//foo-bar-baz."})
    end

    it "parses relative netpaths with an ipv4 address" do
      res = URIParse.parse("//192.168.1.1")

      expect(res).to eq({uri: "//192.168.1.1"})
    end
  end
end

